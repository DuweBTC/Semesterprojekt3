using Microsoft.EntityFrameworkCore;

namespace AccountApi.Models;

public class AccountContext : DbContext
{
    public AccountContext(DbContextOptions<AccountContext> options)
    : base(options)
    {

    }
    // protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    // {
    //     optionsBuilder.UseSqlite("Data Source=/home/pi/3semester.db");
    //     SQLitePCL.Batteries.Init();
    // }

    public DbSet<AccountItem> AccountItems { get; set; } = null!;
    //public DbSet<Balance> Balances {get; set;} =null!;
}
