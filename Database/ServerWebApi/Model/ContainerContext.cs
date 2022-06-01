using Microsoft.EntityFrameworkCore;

namespace ContainerApi.Models;

public class ContainerContext : DbContext
{
    /*
    *@brief This function sets the options for the ContainerContext
    */
    public ContainerContext(DbContextOptions<ContainerContext> options)
    : base(options)
    {

    }


    
    /*
    *@brief This function creates the get and set functions for ContainerItem
    */
    public DbSet<ContainerItem> ContainerItems { get; set; } = null!;

    // protected override void OnModelCreating(ModelBuilder model)
    // {
    //     model.Entity<ContainerItem>()
    //         .Property(b => b.ingredient)
    //         .IsRequired();
    // }
}