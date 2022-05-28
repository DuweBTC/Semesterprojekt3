using Microsoft.EntityFrameworkCore;
using AccountApi.Models;
using DrinkApi.Models;
using ContainerApi.Models;
using RecipeApi.Models;
using IngredientApi.Models;
var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
builder.Services.AddDbContext<AccountContext>(opt =>
    opt.UseSqlite("DefaultConnection"));
builder.Services.AddDbContext<DrinkContext>(opt =>
    opt.UseSqlite("DefaultConnection"));
builder.Services.AddDbContext<ContainerContext>(opt =>
    opt.UseSqlite("DefaultConnection"));
builder.Services.AddDbContext<RecipeContext>(opt =>
    opt.UseSqlite("DefaultConnection"));
builder.Services.AddDbContext<IngredientContext>(opt =>
    opt.UseSqlite("DefaultConnection"));
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
//builder.Services.AddSwaggerGen();

WebApplication app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseDeveloperExceptionPage();
    
}

//app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
