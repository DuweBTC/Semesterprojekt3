using Microsoft.EntityFrameworkCore;

namespace RecipeApi.Models;
using Ingredient.Model;
using RecipeApi.Models;
public class RecipeContext : DbContext
{
    /*
    *@brief This function sets the options for the RecipeContext
    */
    public RecipeContext(DbContextOptions<RecipeContext> options)
    : base(options)
    {

    }

    
    /*
    *@brief This function creates the get and set functions for RecipeItem
    */
    public DbSet<RecipeItem> RecipeItems { get; set; } = null!;

}