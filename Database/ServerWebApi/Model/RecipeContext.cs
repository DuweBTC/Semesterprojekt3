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

}