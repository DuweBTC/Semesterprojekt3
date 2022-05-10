using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using DrinkApi.Models;

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
        return await _context.DrinkItems.ToListAsync();
    }

    // GET: api/Drink/5
    [HttpGet("{id}")]
    public async Task<ActionResult<DrinkItem>> GetDrinkItem(string id)
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
        if (id != DrinkItem.Id)
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

        return NoContent();
    }

    // POST: api/Drink
    [HttpPost]
    public async Task<ActionResult<DrinkItem>> PostDrinkItem(DrinkItem DrinkItem)
    {

        //var Ingredient = Tuple.Create(drinkItem.ingredients.Item1, drinkItem.ingredients.Item2));
        _context.DrinkItems.Add(DrinkItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetDrinkItem), new { id = DrinkItem.Id }, DrinkItem);

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

        return NoContent();
    }


    private bool DrinkItemExists(int id)
    {
        return _context.DrinkItems.Any(e => e.Id == id);
    }


}

