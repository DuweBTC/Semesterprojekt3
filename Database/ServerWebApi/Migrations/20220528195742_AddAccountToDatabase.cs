using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace ServerWebApi.Migrations
{
    public partial class AddAccountToDatabase : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "DrinkItem",
                columns: table => new
                {
                    DrinkItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    Titel = table.Column<string>(type: "TEXT", nullable: false),
                    Description = table.Column<string>(type: "TEXT", nullable: true),
                    Price = table.Column<double>(type: "REAL", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_DrinkItem", x => x.DrinkItemId);
                });

            migrationBuilder.CreateTable(
                name: "IngredientItem",
                columns: table => new
                {
                    IngredientItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    Titel = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_IngredientItem", x => x.IngredientItemId);
                });

            migrationBuilder.CreateTable(
                name: "AccountItems",
                columns: table => new
                {
                    AccountItemId = table.Column<string>(type: "TEXT", nullable: false),
                    Name = table.Column<string>(type: "TEXT", nullable: false),
                    Balance = table.Column<double>(type: "REAL", nullable: false),
                    FavouritDrinkItemId = table.Column<int>(type: "INTEGER", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AccountItems", x => x.AccountItemId);
                    table.ForeignKey(
                        name: "FK_AccountItems_DrinkItem_FavouritDrinkItemId",
                        column: x => x.FavouritDrinkItemId,
                        principalTable: "DrinkItem",
                        principalColumn: "DrinkItemId");
                });

            migrationBuilder.CreateTable(
                name: "RecipeItem",
                columns: table => new
                {
                    RecipeItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    IngredientItemId = table.Column<int>(type: "INTEGER", nullable: true),
                    Amount = table.Column<double>(type: "REAL", nullable: false),
                    DrinkItemId = table.Column<int>(type: "INTEGER", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_RecipeItem", x => x.RecipeItemId);
                    table.ForeignKey(
                        name: "FK_RecipeItem_DrinkItem_DrinkItemId",
                        column: x => x.DrinkItemId,
                        principalTable: "DrinkItem",
                        principalColumn: "DrinkItemId");
                    table.ForeignKey(
                        name: "FK_RecipeItem_IngredientItem_IngredientItemId",
                        column: x => x.IngredientItemId,
                        principalTable: "IngredientItem",
                        principalColumn: "IngredientItemId");
                });

            migrationBuilder.CreateIndex(
                name: "IX_AccountItems_FavouritDrinkItemId",
                table: "AccountItems",
                column: "FavouritDrinkItemId");

            migrationBuilder.CreateIndex(
                name: "IX_RecipeItem_DrinkItemId",
                table: "RecipeItem",
                column: "DrinkItemId");

            migrationBuilder.CreateIndex(
                name: "IX_RecipeItem_IngredientItemId",
                table: "RecipeItem",
                column: "IngredientItemId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "AccountItems");

            migrationBuilder.DropTable(
                name: "RecipeItem");

            migrationBuilder.DropTable(
                name: "DrinkItem");

            migrationBuilder.DropTable(
                name: "IngredientItem");
        }
    }
}
