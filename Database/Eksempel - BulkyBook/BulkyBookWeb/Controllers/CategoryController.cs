using BulkyBookWeb.Data;
using BulkyBookWeb.Models;
using Microsoft.AspNetCore.Mvc;

namespace BulkyBookWeb.Controllers
{
    public class CategoryController : Controller
    {
        private readonly ApplicationDbContext _db;

        public CategoryController(ApplicationDbContext db) // Initialization 
        {
            _db = db;
        }
        public IActionResult Index()
        {
            IEnumerable<Category> objCategoryList = _db.Categories; // Create a ?
            return View(objCategoryList);       // Link it to Views (Index.cshtml)
        }

        //GET Action methode
        public IActionResult Create()
        {
            return View();
        }

        //POST Action methode
        [HttpPost]                              //These keys need to be here
        [ValidateAntiForgeryToken]
        public IActionResult Create(Category obj)
        {
            if(obj.Name == obj.DisplayOrder.ToString())
            {
                ModelState.AddModelError("name", "The Display Order cannot exactly match the Name");
            }
            if (ModelState.IsValid)
            {
                _db.Categories.Add(obj);            // Add object to the database 
                _db.SaveChanges();                  // It first update the database here
                TempData["success"] = "Category created successfully";
                return RedirectToAction("Index");  // Go Back to index site
            }
            return View(obj);
        }


        //GET Action methode
        public IActionResult Edit(int? id)
        {
            if (id == null || id == 0) {
                return NotFound();
            }
            var categoryFromDb = _db.Categories.Find(id);
            //var categoryFromDbFirst = _db.Categories.FirstOrDefault(u=>u.Id==id);
            //var categoryFromDbSingle = _db.Categories.SingleOrDefault(u => u.Id == id);

            if (categoryFromDb == null)
            {
                return NotFound();
            }

            return View(categoryFromDb);
        }

        //POST Action methode
        [HttpPost]                              //These keys need to be here
        [ValidateAntiForgeryToken]
        public IActionResult Edit(Category obj)
        {
            if (obj.Name == obj.DisplayOrder.ToString())
            {
                ModelState.AddModelError("name", "The Display Order cannot exactly match the Name");
            }
            if (ModelState.IsValid)
            {
                _db.Categories.Update(obj);            // Add object to the database 
                _db.SaveChanges();                  // It first update the database here
                TempData["success"] = "Category updated successfully";
                return RedirectToAction("Index");  // Go Back to index site
            }
            return View(obj);
        }


        //GET Action methode
        public IActionResult Delete(int? id)
        {
            if (id == null || id == 0)
            {
                return NotFound();
            }
            var categoryFromDb = _db.Categories.Find(id);
            //var categoryFromDbFirst = _db.Categories.FirstOrDefault(u=>u.Id==id);
            //var categoryFromDbSingle = _db.Categories.SingleOrDefault(u => u.Id == id);

            if (categoryFromDb == null)
            {
                return NotFound();
            }

            return View(categoryFromDb);
        }

        //POST Action methode
        [HttpPost,ActionName("Delete")]                              //These keys need to be here
        [ValidateAntiForgeryToken]
        public IActionResult DeletePOST(int? id)
        {
            var obj = _db.Categories.Find(id);
            if(obj == null)
            {
                return NotFound();
            }

            _db.Categories.Remove(obj);            // Add object to the database 
            _db.SaveChanges();                  // It first update the database here
            TempData["success"] = "Category deleted successfully";
            return RedirectToAction("Index");  // Go Back to index site
           
        }
    }
}
