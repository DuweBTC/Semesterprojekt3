using Microsoft.EntityFrameworkCore;

namespace IngredientApi.Models;
using Ingredient.Model;

public class IngredientContext : DbContext
{
    /*
    *@brief This function sets the options for the IngredientContext
    */
    public IngredientContext(DbContextOptions<IngredientContext> options)
    : base(options)
    {

    }



    /*
    *@brief This function creates the get and set functions for IngredientItem
    */
    public DbSet<IngredientItem> IngredientItems { get; set; } = null!;

}