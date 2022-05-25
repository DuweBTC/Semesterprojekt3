namespace AccountApi.Models;
using DrinkApi.Models;
public class AccountItem
{
    public string AccountItemId { get; set; } = string.Empty;

    public string Name { get; set; } = String.Empty;
    public double Balance { get; set; }

    //public DrinkItem? Favourit { get; set; }

}
