using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace ServerWebApi.Migrations.Container
{
    public partial class AddContainerToDatabase : Migration
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
                name: "ContainerItems",
                columns: table => new
                {
                    ContainerItemId = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    Place = table.Column<int>(type: "INTEGER", nullable: false),
                    IngredientItemId = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_ContainerItems", x => x.ContainerItemId);
                    table.ForeignKey(
                        name: "FK_ContainerItems_IngredientItem_IngredientItemId",
                        column: x => x.IngredientItemId,
                        principalTable: "IngredientItem",
                        principalColumn: "IngredientItemId",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_ContainerItems_IngredientItemId",
                table: "ContainerItems",
                column: "IngredientItemId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "ContainerItems");

            migrationBuilder.DropTable(
                name: "IngredientItem");
        }
    }
}
