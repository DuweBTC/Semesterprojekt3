using Microsoft.EntityFrameworkCore;

namespace DrinkApi.Models;

public class DrinkContext : DbContext
{
    public DrinkContext(DbContextOptions<DrinkContext> options)
    : base(options)
    {

    }

    public DbSet<DrinkItem> DrinkItems { get; set; } = null!;

}