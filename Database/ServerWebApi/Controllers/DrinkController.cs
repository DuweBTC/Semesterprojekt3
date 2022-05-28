using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using DrinkApi.Models;
using RecipeApi.Models;

namespace DrinkApi.Controllers;

[Route("[controller]")]
[ApiController]

public class DrinkController : ControllerBase
{
    private readonly DrinkContext _context;

    public DrinkController(DrinkContext context)
    {
        _context = context;
    }

    // GET: api/Drink
    [HttpGet]
    public async Task<ActionResult<IEnumerable<DrinkItem>>> GetDrinkItem()
    {
        return await _context.DrinkItems.Include(item => item.ingredients)
        //                        .Where(item => item.ingredients
        //                        .Any(y => y == IngredientItem))
                                .ToListAsync();



        //        var games = await db.Games
        //                              .Include(x => x.categoryMain)
        //                              .Where(x => x.categoryMain.Any(y => y == categoryId)
        //                              .ToListAsync();
    }

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

    // POST: api/Drink
    [HttpPost]
    public async Task<ActionResult<DrinkItem>> PostDrinkItem(DrinkItem DrinkItem)
    {


        //var Ingredient = Tuple.Create(drinkItem.ingredients.Item1, drinkItem.ingredients.Item2));

        _context.DrinkItems.Add(DrinkItem);
        //_context.DrinkItems.RecipeItem.Add(DrinkItem.RecipeItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetDrinkItem), new { id = DrinkItem.DrinkItemId }, DrinkItem);

    }

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

    // GET: api/Drink/Amount
    [HttpGet("/Drink/Amount")]
    public async Task<ActionResult<IEnumerable<DrinkItem>>> GetDrinkAmount()
    {

        int numberOfDrinks = 0;
        foreach (var items in _context.DrinkItems)
        {
            numberOfDrinks++;
        }

        return Ok(numberOfDrinks);
    }

    private bool DrinkItemExists(int id)
    {
        return _context.DrinkItems.Any(e => e.DrinkItemId == id);
    }


}

