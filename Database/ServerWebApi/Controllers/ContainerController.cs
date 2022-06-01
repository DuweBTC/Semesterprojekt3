using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using ContainerApi.Models;

namespace ContainerApi.Controllers;

[Route("[controller]")]
[ApiController]

public class ContainerController : ControllerBase
{

    /**
    *Private variable _context
    *This variable is used to save the context to an Container object
    */
    private readonly ContainerContext _context;


    /**
    * @brief This function saves the context to the Container context variable
    * @param context is the context given from the client  
    */
    public ContainerController(ContainerContext context)
    {
        _context = context;
    }



    /**
    *@brief this function gets and returns all ContainerItems  
    *@retval Returns ContainerItem
    */
    // GET: api/Container
    [HttpGet]
    public async Task<ActionResult<IEnumerable<ContainerItem>>> GetContainerItem()
    {
        return await _context.ContainerItems.ToListAsync();
    }



    /**
    *@brief this function returns an ContainerItem based on the id given 
    *@retval Returns notfound if there is no Container with that id
    *@retval Returns the Container if there is an Container with that id 
    *@param id string to the specific Container
    */
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

   
   
    /**
    *@brief this function updates the information that a specific Container contains
    *@retval Returns Badrequest if id does not match the ContainerItem 
    *@retval Returns notfound if there is no Container with that id
    *@retval Returns Ok if everything went successfull
    *@param id string to the specific Container
    *@param ContainerItem is what needs to be updated in the specific Container
    */
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

        return Ok(ContainerItem);
    }


    /**
    *@brief this function creates a new Container 
    *@retval Returns the information contained in the newly created Container
    *@param Takes the information that the new Container is gonna be created from
    */
    // POST: api/Container
    [HttpPost]
    public async Task<ActionResult<ContainerItem>> PostContainerItem(ContainerItem ContainerItem)
    {
        _context.ContainerItems.Add(ContainerItem);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetContainerItem), new { id = ContainerItem.ContainerItemId }, ContainerItem);

    }


    /**
    *@brief this function deletes an Container
    *@retval Returns notfound if there is no Container with that id
    *@retval Returns Ok if everything went successfull
    *@param Takes the id of the Container that's gonna get deleted 
    */
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

        return Ok(ContainerItem);
    }


    /**
    *@brief This function checks if an Container with that id exists
    *@retval Returns False if there is no Container with that id
    *@retval Returns True if there is an Container with that id
    *@param id string to the specific Container
    */
    private bool ContainerItemExists(int id)
    {
        return _context.ContainerItems.Any(e => e.ContainerItemId == id);
    }

}

