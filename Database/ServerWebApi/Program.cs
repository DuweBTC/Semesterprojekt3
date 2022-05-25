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
    opt.UseInMemoryDatabase("Account"));
builder.Services.AddDbContext<DrinkContext>(opt =>
    opt.UseInMemoryDatabase("Drink"));
builder.Services.AddDbContext<ContainerContext>(opt =>
    opt.UseInMemoryDatabase("Container"));
builder.Services.AddDbContext<RecipeContext>(opt =>
opt.UseInMemoryDatabase("Recipe"));
builder.Services.AddDbContext<IngredientContext>(opt =>
opt.UseInMemoryDatabase("Ingredient"));
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

WebApplication app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseDeveloperExceptionPage();
    app.UseSwagger();
    app.UseSwaggerUI();
}

//app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
