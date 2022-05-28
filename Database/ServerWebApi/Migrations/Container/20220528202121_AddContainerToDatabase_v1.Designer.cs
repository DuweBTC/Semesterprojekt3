﻿// <auto-generated />
using ContainerApi.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace ServerWebApi.Migrations.Container
{
    [DbContext(typeof(ContainerContext))]
    [Migration("20220528202121_AddContainerToDatabase_v1")]
    partial class AddContainerToDatabase_v1
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder.HasAnnotation("ProductVersion", "6.0.4");

            modelBuilder.Entity("ContainerApi.Models.ContainerItem", b =>
                {
                    b.Property<int>("ContainerItemId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("IngredientItemId")
                        .HasColumnType("INTEGER");

                    b.Property<int>("Place")
                        .HasColumnType("INTEGER");

                    b.HasKey("ContainerItemId");

                    b.HasIndex("IngredientItemId");

                    b.ToTable("ContainerItems");
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

            modelBuilder.Entity("ContainerApi.Models.ContainerItem", b =>
                {
                    b.HasOne("Ingredient.Model.IngredientItem", "Ingredient")
                        .WithMany()
                        .HasForeignKey("IngredientItemId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Ingredient");
                });
#pragma warning restore 612, 618
        }
    }
}
