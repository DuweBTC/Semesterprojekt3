﻿// <auto-generated />
using System;
using DrinkApi.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace ServerWebApi.Migrations.Drink
{
    [DbContext(typeof(DrinkContext))]
    [Migration("20220528195748_AddDrinkToDatabase")]
    partial class AddDrinkToDatabase
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder.HasAnnotation("ProductVersion", "6.0.4");

            modelBuilder.Entity("DrinkApi.Models.DrinkItem", b =>
                {
                    b.Property<int>("DrinkItemId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("Description")
                        .HasColumnType("TEXT");

                    b.Property<double>("Price")
                        .HasColumnType("REAL");

                    b.Property<string>("Titel")
                        .IsRequired()
                        .HasColumnType("TEXT");

                    b.HasKey("DrinkItemId");

                    b.ToTable("DrinkItems");
                });

            modelBuilder.Entity("Ingredient.Model.IngredientItem", b =>
                {
                    b.Property<int>("IngredientItemId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("Titel")
                        .HasColumnType("TEXT");

                    b.HasKey("IngredientItemId");

                    b.ToTable("IngredientItem");
                });

            modelBuilder.Entity("RecipeApi.Models.RecipeItem", b =>
                {
                    b.Property<int>("RecipeItemId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<double>("Amount")
                        .HasColumnType("REAL");

                    b.Property<int?>("DrinkItemId")
                        .HasColumnType("INTEGER");

                    b.Property<int?>("IngredientItemId")
                        .HasColumnType("INTEGER");

                    b.HasKey("RecipeItemId");

                    b.HasIndex("DrinkItemId");

                    b.HasIndex("IngredientItemId");

                    b.ToTable("RecipeItem");
                });

            modelBuilder.Entity("RecipeApi.Models.RecipeItem", b =>
                {
                    b.HasOne("DrinkApi.Models.DrinkItem", null)
                        .WithMany("ingredients")
                        .HasForeignKey("DrinkItemId");

                    b.HasOne("Ingredient.Model.IngredientItem", "IngredientItem")
                        .WithMany()
                        .HasForeignKey("IngredientItemId");

                    b.Navigation("IngredientItem");
                });

            modelBuilder.Entity("DrinkApi.Models.DrinkItem", b =>
                {
                    b.Navigation("ingredients");
                });
#pragma warning restore 612, 618
        }
    }
}
