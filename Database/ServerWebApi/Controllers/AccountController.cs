using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using AccountApi.Models;

namespace AccountApi.Controllers;

[Route("[controller]")]
[ApiController]

public class AccountController : ControllerBase
{
    private readonly AccountContext _context;

    public AccountController(AccountContext context)
    {
        _context = context;
    }

    // GET: api/Account
    [HttpGet]
    public async Task<ActionResult<IEnumerable<AccountItem>>> GetAccountItem()
    {
        return await _context.AccountItems.ToListAsync();
    }

    // GET: api/Account/5
    [HttpGet("{id}")]
    public async Task<ActionResult<AccountItem>> GetAccountItem(string id)
    {
        var accountItem = await _context.AccountItems.FindAsync(id);

        if (accountItem == null)
        {
            return NotFound();
        }

        return accountItem;
    }

    //PUT: api/Account/5
    [HttpPut("{id}")]
    public async Task<IActionResult> PutAccountItem(string id, AccountItem accountItem)
    {
        if (id != accountItem.Id)
        {
            return BadRequest();
        }

        _context.Entry(accountItem).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!AccountItemExists(id))
            {
                return NotFound();
            }
            else
            {
                throw;
            }
        }

        return NoContent();
    }

    // POST: api/Account
    [HttpPost]
    public async Task<ActionResult<AccountItem>> PostAccountItem(AccountItem accountItem)
    {
        _context.AccountItems.Add(accountItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetAccountItem), new { id = accountItem.Id }, accountItem);

    }

    // DELETE: api/Account/5
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteAccountItem(string id)
    {
        var accountItem = await _context.AccountItems.FindAsync(id);
        if (accountItem == null)
        {
            return NotFound();
        }

        _context.AccountItems.Remove(accountItem);
        await _context.SaveChangesAsync();

        return NoContent();
    }


    private bool AccountItemExists(string id)
    {
        return _context.AccountItems.Any(e => e.Id == id);
    }

}

