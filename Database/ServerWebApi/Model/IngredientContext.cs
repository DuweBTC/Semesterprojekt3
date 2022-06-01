using Microsoft.EntityFrameworkCore;

namespace IngredientApi.Models;
using Ingredient.Model;

public class IngredientContext : DbContext
{
    public IngredientContext(DbContextOptions<IngredientContext> options)
    : base(options)
    {

    }
    // protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    // {
    //     optionsBuilder.UseSqlite("Data Source=/home/pi/3semester.db");
    //     SQLitePCL.Batteries.Init();
    // }

    public DbSet<IngredientItem> IngredientItems { get; set; } = null!;

}
