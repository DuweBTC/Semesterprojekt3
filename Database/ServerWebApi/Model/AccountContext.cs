using Microsoft.EntityFrameworkCore;

namespace AccountApi.Models;

public class AccountContext : DbContext
{
    public AccountContext(DbContextOptions<AccountContext> options)
    : base(options)
    {

    }

    public DbSet<AccountItem> AccountItems { get; set; } = null!;
    //public DbSet<Balance> Balances {get; set;} =null!;
}