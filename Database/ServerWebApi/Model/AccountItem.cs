namespace AccountApi.Models;
using DrinkApi.Models;
public class AccountItem
{
    /*
    *@brief This function creates the get and set functions for AccountItemId
    */
    public string AccountItemId { get; set; }

    /*
    *@brief This function creates the get and set functions for Name
    */
    public string Name { get; set; } = String.Empty;

    /*
    *@brief This function creates the get and set functions for Balance
    */
    public double Balance { get; set; }

    /*
    *@brief This function creates the get and set functions for Favorit
    */
    public DrinkItem? Favourit { get; set; }

}