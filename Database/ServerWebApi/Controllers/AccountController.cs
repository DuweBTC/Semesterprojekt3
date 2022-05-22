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
    /**
     @ breif
    */
    // GET: api/Account
    [HttpGet]
    public async Task<ActionResult<IEnumerable<AccountItem>>> GetAccountItem()
    {
        return await _context.AccountItems.ToListAsync();
    }

    // GET: api/Account/5
    [HttpGet("{id}")]
    public async Task<ActionResult<AccountItem>> GetAccountItem(int id)
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
    public async Task<IActionResult> PutAccountItem(int id, AccountItem accountItem)
    {
        if (id != accountItem.AccountItemId)
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

        return CreatedAtAction(nameof(GetAccountItem), new { id = accountItem.AccountItemId }, accountItem);

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


    private bool AccountItemExists(int id)
    {
        return _context.AccountItems.Any(e => e.AccountItemId == id);
    }

    // GET: api/Account/{id}/Balance
    [HttpGet("{id}/Balance")]
    public async Task<ActionResult<AccountItem>> GetAccountItemBalance(string id)
    {
        var accountItem = await _context.AccountItems.FindAsync(id);
        if (accountItem == null)
        {
            return NotFound();
        }

        return Ok(accountItem.Balance);
    }

    //PUT: /Account/{id}/Balance/
    [HttpPut("{id}/Balance/")]
    public async Task<IActionResult> PutAccountItemBalance(int id, double amount)
    {
        var accountItem = await _context.AccountItems.FindAsync(id);
        if (accountItem == null)
        {
            return NotFound();
        }

        if ((accountItem.Balance + amount) < 0)
        {
            return BadRequest();
        }

        accountItem.Balance = accountItem.Balance + amount;

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

}

