using Microsoft.EntityFrameworkCore;

namespace DrinkApi.Models;
using Ingredient.Model;
using RecipeApi.Models;
public class DrinkContext : DbContext
{
    /*
    *@brief This function sets the options for the DrinkContext
    */
    public DrinkContext(DbContextOptions<DrinkContext> options)
    : base(options)
    {

    }


    
    /*
    *@brief This function creates the get and set functions for DrinkItem
    */
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

    /*
    *@brief This function creates the Model for the DrinkItem
    *@param modelBuilder is the variable the model gets created from
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