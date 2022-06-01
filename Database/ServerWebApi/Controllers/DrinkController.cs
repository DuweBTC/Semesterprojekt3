using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using DrinkApi.Models;
using RecipeApi.Models;

namespace DrinkApi.Controllers;

[Route("[controller]")]
[ApiController]

public class DrinkController : ControllerBase
{

    /**
    *Private variable _context
    *This variable is used to save the context to an Drink object
    */
    private readonly DrinkContext _context;


    /**
    * @brief This function saves the context to the Drink context variable
    * @param context is the context given from the client  
    */
    public DrinkController(DrinkContext context)
    {
        _context = context;
    }


    /**
    *@brief this function gets and returns all DrinkItems  
    *@retval Returns DrinkItem
    */
    // GET: api/Drink
    [HttpGet]
    public async Task<ActionResult<IEnumerable<DrinkItem>>> GetDrinkItem()
    {
        return await _context.DrinkItems.Include(item => item.ingredients).ToListAsync();
    }


    /**
    *@brief this function returns an DrinkItem based on the id given 
    *@retval Returns notfound if there is no Drink with that id
    *@retval Returns the Drink if there is an Drink with that id 
    *@param id string to the specific Drink
    */
    // GET: api/Drink/5
    [HttpGet("{id}")]
    public async Task<ActionResult<DrinkItem>> GetDrinkItem(int id)
    {
        var DrinkItem = await _context.DrinkItems.FindAsync(id);

        if (DrinkItem == null)
        {
            return NotFound();
        }

        return DrinkItem;
    }


    /**
    *@brief this function updates the information that a specific Drink contains
    *@retval Returns Badrequest if id does not match the DrinkItem 
    *@retval Returns notfound if there is no Drink with that id
    *@retval Returns Ok if everything went successfull
    *@param id string to the specific Drink
    *@param DrinkItem is what needs to be updated in the specific Drink
    */
    //PUT: api/Drink/5
    [HttpPut("{id}")]
    public async Task<IActionResult> PutDrinkItem(int id, DrinkItem DrinkItem)
    {
        if (id != DrinkItem.DrinkItemId)
        {
            return BadRequest();
        }

        _context.Entry(DrinkItem).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!DrinkItemExists(id))
            {
                return NotFound();
            }
            else
            {
                throw;
            }
        }

        return Ok(DrinkItem);
    }


    /**
    *@brief this function creates a new Drink 
    *@retval Returns the information contained in the newly created Drink
    *@param Takes the information that the new Drink is gonna be created from
    */
    // POST: api/Drink
    [HttpPost]
    public async Task<ActionResult<DrinkItem>> PostDrinkItem(DrinkItem DrinkItem)
    {

        //var Ingredient = Tuple.Create(drinkItem.ingredients.Item1, drinkItem.ingredients.Item2));
        _context.DrinkItems.Add(DrinkItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetDrinkItem), new { id = DrinkItem.DrinkItemId }, DrinkItem);

    }


    /**
    *@brief this function deletes an Recipe
    *@retval Returns notfound if there is no Recipe with that id
    *@retval Returns Ok if everything went successfull
    *@param Takes the id of the Recipe that's gonna get deleted 
    */
    // DELETE: api/Drink/5
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteDrinkItem(int id)
    {
        var DrinkItem = await _context.DrinkItems.FindAsync(id);
        if (DrinkItem == null)
        {
            return NotFound();
        }

        _context.DrinkItems.Remove(DrinkItem);
        await _context.SaveChangesAsync();

        return Ok();
    }



    /**
    *@brief This function checks if an Drink with that id exists
    *@retval Returns False if there is no Drink with that id
    *@retval Returns True if there is an Drink with that id
    *@param id string to the specific Drink
    */
    private bool DrinkItemExists(int id)
    {
        return _context.DrinkItems.Any(e => e.DrinkItemId == id);
    }


}

