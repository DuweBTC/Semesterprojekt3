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
    // protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    // {
    //     optionsBuilder.UseSqlite("Data Source=/home/pi/3semester.db");
    //     SQLitePCL.Batteries.Init();
    // }

    public DbSet<RecipeItem> RecipeItems { get; set; } = null!;

}
