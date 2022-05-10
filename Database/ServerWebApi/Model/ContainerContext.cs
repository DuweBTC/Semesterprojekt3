using Microsoft.EntityFrameworkCore;

namespace ContainerApi.Models;

public class ContainerContext : DbContext
{
    public ContainerContext(DbContextOptions<ContainerContext> options)
    : base(options)
    {

    }

    public DbSet<ContainerItem> ContainerItems { get; set; } = null!;

    // protected override void OnModelCreating(ModelBuilder model)
    // {
    //     model.Entity<ContainerItem>()
    //         .Property(b => b.ingredient)
    //         .IsRequired();
    // }
}