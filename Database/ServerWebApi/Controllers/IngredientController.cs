using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using IngredientApi.Models;
using Ingredient.Model;

namespace IngredientApi.Controllers;

[Route("[controller]")]
[ApiController]

public class IngredientController : ControllerBase
{
    private readonly IngredientContext _context;

    public IngredientController(IngredientContext context)
    {
        _context = context;
    }

    // GET: api/Ingredient
    [HttpGet]
    public async Task<ActionResult<IEnumerable<IngredientItem>>> GetIngredientItem()
    {
        return await _context.IngredientItems.ToListAsync();
    }

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

    // POST: api/Ingredient
    [HttpPost]
    public async Task<ActionResult<IngredientItem>> PostIngredientItem(IngredientItem IngredientItem)
    {

        //var Ingredient = Tuple.Create(IngredientItem.ingredients.Item1, IngredientItem.ingredients.Item2));
        _context.IngredientItems.Add(IngredientItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetIngredientItem), new { id = IngredientItem.IngredientItemId }, IngredientItem);

    }

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

    // GET: api/Ingredient/Amount
    [HttpGet("/Ingredient/Amount")]
    public async Task<IActionResult> GetIngredientAmount()
    {

        int numberOfIngredients = 0;
        foreach (var items in _context.IngredientItems)
        {
            numberOfIngredients++;
        }

        return Ok(numberOfIngredients);
    }


    private bool IngredientItemExists(int id)
    {
        return _context.IngredientItems.Any(e => e.IngredientItemId == id);
    }


}

