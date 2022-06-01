using Microsoft.EntityFrameworkCore;

namespace AccountApi.Models;

public class AccountContext : DbContext
{
    /*
    *@brief This function sets the options for the AccountContext
    */
    public AccountContext(DbContextOptions<AccountContext> options)
    : base(options)
    {

    }


    /*
    *@brief This function creates the get and set functions for AccountItem
    */
    public DbSet<AccountItem> AccountItems { get; set; } = null!;
    //public DbSet<Balance> Balances {get; set;} =null!;
}