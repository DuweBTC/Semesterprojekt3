using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace ServerWebApi.Migrations.Recipe
{
    public partial class AddRecipeToDatabase : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
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
                name: "RecipeItems",
                columns: table => new
                {
                    RecipeItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    IngredientItemId = table.Column<int>(type: "INTEGER", nullable: true),
                    Amount = table.Column<double>(type: "REAL", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_RecipeItems", x => x.RecipeItemId);
                    table.ForeignKey(
                        name: "FK_RecipeItems_IngredientItem_IngredientItemId",
                        column: x => x.IngredientItemId,
                        principalTable: "IngredientItem",
                        principalColumn: "IngredientItemId");
                });

            migrationBuilder.CreateIndex(
                name: "IX_RecipeItems_IngredientItemId",
                table: "RecipeItems",
                column: "IngredientItemId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "RecipeItems");

            migrationBuilder.DropTable(
                name: "IngredientItem");
        }
    }
}
