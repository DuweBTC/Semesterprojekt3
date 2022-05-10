using Microsoft.EntityFrameworkCore;

namespace RecipeApi.Models;
using Ingredient.Model;
using RecipeApi.Models;
public class RecipeContext : DbContext
{
    public RecipeContext(DbContextOptions<RecipeContext> options)
    : base(options)
    {

    }

    public DbSet<RecipeItem> RecipeItems { get; set; } = null!;


    protected override void OnModelCreating(ModelBuilder model)
    {
        model.Entity<RecipeItem>()
            .HasMany<Ingredient>(p => p.Ingredients);//.WithOne(c => c.DrinkItem)
                                                     //.HasForeignKey(c => c.Id);
    }
}