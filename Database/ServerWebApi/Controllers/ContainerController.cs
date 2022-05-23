using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using ContainerApi.Models;

namespace ContainerApi.Controllers;

[Route("[controller]")]
[ApiController]

public class ContainerController : ControllerBase
{
    private readonly ContainerContext _context;

    public ContainerController(ContainerContext context)
    {
        _context = context;
    }

    // GET: api/Container
    [HttpGet]
    public async Task<ActionResult<IEnumerable<ContainerItem>>> GetContainerItem()
    {
        return await _context.ContainerItems.ToListAsync();
    }

    // GET: api/Container/5
    [HttpGet("{id}")]
    public async Task<ActionResult<ContainerItem>> GetContainerItem(int id)
    {
        var ContainerItem = await _context.ContainerItems.FindAsync(id);

        if (ContainerItem == null)
        {
            return NotFound();
        }

        return ContainerItem;
    }

    //PUT: api/Container/5
    [HttpPut("{id}")]
    public async Task<IActionResult> PutContainerItem(int id, ContainerItem ContainerItem)
    {
        if (id != ContainerItem.ContainerItemId)
        {
            return BadRequest();
        }

        _context.Entry(ContainerItem).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!ContainerItemExists(id))
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

    // POST: api/Container
    [HttpPost]
    public async Task<ActionResult<ContainerItem>> PostContainerItem(ContainerItem ContainerItem)
    {
        _context.ContainerItems.Add(ContainerItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetContainerItem), new { id = ContainerItem.ContainerItemId }, ContainerItem);

    }

    // DELETE: api/Container/5
    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteContainerItem(int id)
    {
        var ContainerItem = await _context.ContainerItems.FindAsync(id);
        if (ContainerItem == null)
        {
            return NotFound();
        }

        _context.ContainerItems.Remove(ContainerItem);
        await _context.SaveChangesAsync();

        return NoContent();
    }


    private bool ContainerItemExists(int id)
    {
        return _context.ContainerItems.Any(e => e.ContainerItemId == id);
    }

}

