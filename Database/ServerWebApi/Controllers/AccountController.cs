using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using AccountApi.Models;

namespace AccountApi.Controllers;

[Route("[controller]")]
[ApiController]

public class AccountController : ControllerBase
{

    /**
    *Private variable _context
    *This variable is used to save the context to an account object
    */
    private readonly AccountContext _context;

    /**
    * @brief This function saves the context to the account context variable
    * @param context is the context given from the client  
    */
    public AccountController(AccountContext context)
    {
        _context = context;
    }


    /**
    *@brief this function gets and returns all account item 
    *@retval Returns AccountItem
    */
    // GET: api/Account
    [HttpGet]
    public async Task<ActionResult<IEnumerable<AccountItem>>> GetAccountItem()
    {
        return await _context.AccountItems.ToListAsync();
    }

    /**
    *@brief this function returns an account item based on the id given 
    *@retval Returns notfound if there is no account with that id
    *@retval Returns the account if there is an account with that id 
    *@param id string to the specific account
    */
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


    /**
    *@brief this function updates the information that a specific account contains
    *@retval Returns Badrequest if id does not match the accoutitem 
    *@retval Returns notfound if there is no account with that id
    *@retval Returns Ok if everything went successfull
    *@param id string to the specific account
    *@param accountItem is what needs to be updated in the specific account
    */
    //PUT: api/Account/5
    [HttpPut("{id}")]
    public async Task<IActionResult> PutAccountItem(string id, AccountItem accountItem)
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

        return Ok(accountItem);
    }


    /**
    *@brief this function creates a new account 
    *@retval Returns the information contained in the newly created account
    *@param Takes the information that the new account is gonna be created from
    */
    // POST: api/Account
    [HttpPost]
    public async Task<ActionResult<AccountItem>> PostAccountItem(AccountItem accountItem)
    {
        _context.AccountItems.Add(accountItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetAccountItem), new { id = accountItem.AccountItemId }, accountItem);

    }


    /**
    *@brief this function deletes an account
    *@retval Returns notfound if there is no account with that id
    *@retval Returns Ok if everything went successfull
    *@param Takes the id of the account that's gonna get deleted 
    */
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

        return Ok();
    }


    /**
    *@brief This function checks if an account with that id exists
    *@retval Returns False if there is no account with that id
    *@retval Returns True if there is an account with that id
    *@param id string to the specific account
    */
    private bool AccountItemExists(string id)
    {
        return _context.AccountItems.Any(e => e.AccountItemId == id);
    }


    
    /**
    *@brief this function returns the balance of a specific account
    *@retval Returns notfound if there is no account with that id
    *@retval Returns Ok if it found the specific account
    *@param id string to the specific account
    */
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


    
    /**
    *@brief this function updates the balance of a specific account
    *@retval Returns notfound if there is no account with that id
    *@retval Returns Badrequest if the balance goes below 0 
    *@retval Returns Ok if the balance was updated
    *@param id string to the specific account
    *@param amount is the amout that is gonna get added to the account
    */
    //PUT: /Account/{id}/Balance/
    [HttpPut("{id}/Balance/")]
    public async Task<IActionResult> PutAccountItemBalance(string id, double amount)
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

        return Ok(accountItem.Balance);
    }

}

