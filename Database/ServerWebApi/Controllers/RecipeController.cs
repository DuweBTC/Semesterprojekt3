using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace RecipeApi.Controllers;
using RecipeApi.Models;

[Route("[controller]")]
[ApiController]

public class RecipeController : ControllerBase
{


    /**
    *Private variable _context
    *This variable is used to save the context to an Recipe object
    */
    private readonly RecipeContext _context;



    /**
    * @brief This function saves the context to the Recipe context variable
    * @param context is the context given from the client  
    */
    public RecipeController(RecipeContext context)
    {
        _context = context;
    }



    /**
    *@brief this function gets and returns all RecipeItems  
    *@retval Returns RecipeItem
    */
    // GET: api/Recipe
    [HttpGet]
    public async Task<ActionResult<IEnumerable<RecipeItem>>> GetRecipeItem()
    {
        return await _context.RecipeItems
                                .Include(item => item.Ingredient)
                                .ToListAsync();
    }


    /**
    *@brief this function returns an RecipeItem based on the id given 
    *@retval Returns notfound if there is no Recipe with that id
    *@retval Returns the Recipe if there is an Recipe with that id 
    *@param id string to the specific Recipe
    */
    // GET: api/Recipe/5
    [HttpGet("{id}")]
    public async Task<ActionResult<RecipeItem>> GetRecipeItem(int id)
    {
        var RecipeItem = await _context.RecipeItems
                                            .Include(item => item.Ingredient)
                                            .FirstOrDefaultAsync(item => item.RecipeItemId == id);

        if (RecipeItem == null)
        {
            return NotFound();
        }

        return RecipeItem;
    }



    /**
    *@brief this function creates a new Recipe 
    *@retval Returns the information contained in the newly created Recipe
    *@param Takes the information that the new Recipe is gonna be created from
    */
    // POST: api/Recipe
    [HttpPost]
    public async Task<ActionResult<RecipeItem>> PostRecipeItem(RecipeItem RecipeItem)
    {

        //var Ingredient = Tuple.Create(RecipeItem.ingredients.Item1, RecipeItem.ingredients.Item2));
        _context.RecipeItems.Add(RecipeItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetRecipeItem), new { ingredients = RecipeItem.Ingredient }, RecipeItem);

    }

    /**
    *@brief this function deletes an Recipe
    *@retval Returns notfound if there is no Recipe with that id
    *@retval Returns Ok if everything went successfull
    *@param Takes the id of the Recipe that's gonna get deleted 
    */
    //DELETE: api/Recipe/5
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteRecipeItem(int id)
    {
        var RecipeItem = await _context.RecipeItems.FindAsync(id);
        if (RecipeItem == null)
        {
            return NotFound();
        }

        _context.RecipeItems.Remove(RecipeItem);
        await _context.SaveChangesAsync();

        return Ok();
    }


    /**
    *@brief This function checks if an Recipe with that id exists
    *@retval Returns False if there is no Recipe with that id
    *@retval Returns True if there is an Recipe with that id
    *@param id string to the specific Recipe
    */
    private bool RecipeItemExists(int id)
    {
        return _context.RecipeItems.Any(e => e.RecipeItemId == id);
    }


}

