using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using IngredientApi.Models;
using Ingredient.Model;

namespace IngredientApi.Controllers;

[Route("[controller]")]
[ApiController]

public class IngredientController : ControllerBase
{

    /**
    *Private variable _context
    *This variable is used to save the context to an Ingredient object
    */
    private readonly IngredientContext _context;


    /**
    * @brief This function saves the context to the Ingredient context variable
    * @param context is the context given from the client  
    */
    public IngredientController(IngredientContext context)
    {
        _context = context;
    }



    /**
    *@brief this function gets and returns all IngredientItems  
    *@retval Returns IngredientItem
    */
    // GET: api/Ingredient
    [HttpGet]
    public async Task<ActionResult<IEnumerable<IngredientItem>>> GetIngredientItem()
    {
        return await _context.IngredientItems.ToListAsync();
    }



    /**
    *@brief this function returns an IngredientItem based on the id given 
    *@retval Returns notfound if there is no Ingredient with that id
    *@retval Returns the Ingredient if there is an Ingredient with that id 
    *@param id string to the specific Ingredient
    */
    // GET: api/Ingredient/5
    [HttpGet("{id}")]
    public async Task<ActionResult<IngredientItem>> GetIngredientItem(int id)
    {
        var IngredientItem = await _context.IngredientItems.FindAsync(id);

        if (IngredientItem == null)
        {
            return NotFound();
        }

        return IngredientItem;
    }


    /**
    *@brief this function updates the information that a specific Ingredient contains
    *@retval Returns Badrequest if id does not match the Ingredient 
    *@retval Returns notfound if there is no Ingredient with that id
    *@retval Returns Ok if everything went successfull
    *@param id string to the specific Ingredient
    *@param IngredientItem is what needs to be updated in the specific ContIngredientainer
    */
    //PUT: api/Ingredient/5
    [HttpPut("{id}")]
    public async Task<IActionResult> PutIngredientItem(int id, IngredientItem IngredientItem)
    {
        if (id != IngredientItem.IngredientItemId)
        {
            return BadRequest();
        }

        _context.Entry(IngredientItem).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!IngredientItemExists(id))
            {
                return NotFound();
            }
            else
            {
                throw;
            }
        }

        return Ok(IngredientItem);
    }


    /**
    *@brief this function creates a new Ingredient 
    *@retval Returns the information contained in the newly created Ingredient
    *@param Takes the information that the new Ingredient is gonna be created from
    */
    // POST: api/Ingredient
    [HttpPost]
    public async Task<ActionResult<IngredientItem>> PostIngredientItem(IngredientItem IngredientItem)
    {

        //var Ingredient = Tuple.Create(IngredientItem.ingredients.Item1, IngredientItem.ingredients.Item2));
        _context.IngredientItems.Add(IngredientItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetIngredientItem), new { id = IngredientItem.IngredientItemId }, IngredientItem);

    }


    /**
    *@brief this function deletes an Recipe
    *@retval Returns notfound if there is no Recipe with that id
    *@retval Returns Ok if everything went successfull
    *@param Takes the id of the Recipe that's gonna get deleted 
    */
    // DELETE: api/Ingredient/5
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteIngredientItem(int id)
    {
        var IngredientItem = await _context.IngredientItems.FindAsync(id);
        if (IngredientItem == null)
        {
            return NotFound();
        }

        _context.IngredientItems.Remove(IngredientItem);
        await _context.SaveChangesAsync();

        return Ok();
    }



    /**
    *@brief This function checks if an Ingredient with that id exists
    *@retval Returns False if there is no Ingredient with that id
    *@retval Returns True if there is an Ingredient with that id
    *@param id string to the specific Ingredient
    */
    private bool IngredientItemExists(int id)
    {
        return _context.IngredientItems.Any(e => e.IngredientItemId == id);
    }


}

