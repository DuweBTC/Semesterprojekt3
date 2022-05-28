﻿// <auto-generated />
using System;
using AccountApi.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace ServerWebApi.Migrations
{
    [DbContext(typeof(AccountContext))]
    [Migration("20220528222527_AddAccountToDatabase_v2")]
    partial class AddAccountToDatabase_v2
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder.HasAnnotation("ProductVersion", "6.0.4");

            modelBuilder.Entity("AccountApi.Models.AccountItem", b =>
                {
                    b.Property<string>("AccountItemId")
                        .HasColumnType("TEXT");

                    b.Property<double>("Balance")
                        .HasColumnType("REAL");

                    b.Property<int?>("FavouritDrinkItemId")
                        .HasColumnType("INTEGER");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("TEXT");

                    b.HasKey("AccountItemId");

                    b.HasIndex("FavouritDrinkItemId");

                    b.ToTable("AccountItems");
                });

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

                    b.ToTable("DrinkItem");
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

            modelBuilder.Entity("AccountApi.Models.AccountItem", b =>
                {
                    b.HasOne("DrinkApi.Models.DrinkItem", "Favourit")
                        .WithMany()
                        .HasForeignKey("FavouritDrinkItemId");

                    b.Navigation("Favourit");
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
