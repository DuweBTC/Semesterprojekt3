namespace AccountApi.Models;
using DrinkApi.Models;
public class AccountItem
{
    public int AccountItemId { get; set; }

    public string Name { get; set; } = String.Empty;
    public double Balance { get; set; }

    //public DrinkItem? Favourit { get; set; }

}