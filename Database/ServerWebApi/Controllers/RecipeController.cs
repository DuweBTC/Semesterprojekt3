using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace RecipeApi.Controllers;
using RecipeApi.Models;

[Route("[controller]")]
[ApiController]

public class RecipeController : ControllerBase
{
    private readonly RecipeContext _context;

    public RecipeController(RecipeContext context)
    {
        _context = context;
    }

    // GET: api/Recipe
    [HttpGet]
    public async Task<ActionResult<IEnumerable<RecipeItem>>> GetRecipeItem()
    {
        return await _context.RecipeItems
                                .Include(item => item.Ingredient)
                                .ToListAsync();
    }

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

    // POST: api/Recipe
    [HttpPost]
    public async Task<ActionResult<RecipeItem>> PostRecipeItem(RecipeItem RecipeItem)
    {

        //var Ingredient = Tuple.Create(RecipeItem.ingredients.Item1, RecipeItem.ingredients.Item2));
        _context.RecipeItems.Add(RecipeItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetRecipeItem), new { ingredients = RecipeItem.Ingredient }, RecipeItem);

    }
    /*
        // DELETE: api/Recipe/5
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

            return NoContent();
        }


        private bool RecipeItemExists(int id)
        {
            return _context.RecipeItems.Any(e => e.Id == id);
        }

    */
}

