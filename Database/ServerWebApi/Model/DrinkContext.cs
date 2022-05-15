using Microsoft.EntityFrameworkCore;

namespace DrinkApi.Models;
using Ingredient.Model;
using RecipeApi.Models;
public class DrinkContext : DbContext
{
    public DrinkContext(DbContextOptions<DrinkContext> options)
    : base(options)
    {

    }

    public DbSet<DrinkItem> DrinkItems { get; set; } = null!;

    //public DbSet<Ingredient> IngredientItems { get; set; } = null!;
    /*
    protected override void OnModelCreating(ModelBuilder model)
    {
        model.Entity<DrinkItem>()
            .HasMany<Ingredient>(p => p.ingredients);//.WithOne(c => c.DrinkItem)
                                                     //.HasForeignKey(c => c.Id);
    }
    */

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder
            .Entity<DrinkItem>(
                item =>
                {
                    item.HasKey("DrinkId");
                });
    }
}