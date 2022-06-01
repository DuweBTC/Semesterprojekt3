using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace ServerWebApi.Migrations.Ingredient
{
    public partial class IntitialCreateIngredient : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "IngredientItems",
                columns: table => new
                {
                    IngredientItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    Titel = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_IngredientItems", x => x.IngredientItemId);
                });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "IngredientItems");
        }
    }
}
