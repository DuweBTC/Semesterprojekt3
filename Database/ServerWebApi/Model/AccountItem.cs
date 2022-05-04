namespace AccountApi.Models;

public class AccountItem
{
    public string? Id { get; set; }

    public string? Name { get; set; }

    public string? Email { get; set; }
    public double Balance { get; set; }

    public string? dateCreated { get; set; }

    public string? guid { get; set; }


    public string? favourit { get; set; }

    //public ICollection<PlatformNotSupportedException> Products { get; set; }

}