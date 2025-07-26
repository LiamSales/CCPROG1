import kotlin.random.Random

val mains = hashMapOf(
    0 to Pair("None", 0.00f),
    1 to Pair("Chicken", 90.0f),
    2 to Pair("Pork", 105.0f),
    3 to Pair("Fish", 120.0f),
    4 to Pair("Beef", 135.0f)
)

val sides = hashMapOf(
    0 to Pair("None", 0.00f),
    1 to Pair("Steamed Rice", 20.0f),
    2 to Pair("Shredded Corn", 35.0f),
    3 to Pair("Mashed Potatoes", 50.0f),
    4 to Pair("Steam Vegetables", 65.0f)
)

val drinks = hashMapOf(
    0 to Pair("None", 0.00f),
    1 to Pair("Mineral Water", 25.0f),
    2 to Pair("Iced Tea", 35.0f),
    3 to Pair("Soda", 45.0f),
    4 to Pair("Fruit Juice", 55.0f)
)

class Meal(var main: Int, var side: Int, var drink: Int) {
    val price: Float
        get() = (mains[main]?.second ?: 0f) + (sides[side]?.second ?: 0f) + (drinks[drink]?.second ?: 0f)
}

fun randomOrder(): Int = Random.Default.nextInt(1, 5)

fun printMenu() {
    println("\n======= MENU =======")
    println("\nMains:")
    mains.entries.drop(1).forEach { (id, item) ->
        println("\t$id. ${item.first} - PHP ${item.second}")
    }

    println("\nSides:")
    sides.entries.drop(1).forEach { (id, item) ->
        println("\t$id. ${item.first} - PHP ${item.second}")
    }

    println("\nDrinks:")
    drinks.entries.drop(1).forEach { (id, item) ->
        println("\t$id. ${item.first} - PHP ${item.second}")
    }
    println("====================\n")
}

fun main() {
    val orders = Array(3) { Meal(0, 0, 0) }
    val setMealOfTheDay = Meal(randomOrder(), randomOrder(), randomOrder())
    val discountedPrice = setMealOfTheDay.price * 0.85f

    printMenu()

    println("Set Meal of the Day")
    println("\tMain: ${mains[setMealOfTheDay.main]?.first}")
    println("\tSide: ${sides[setMealOfTheDay.side]?.first}")
    println("\tDrink: ${drinks[setMealOfTheDay.drink]?.first}")
    println("\tDiscounted Price: PHP ${"%.2f".format(discountedPrice)}\n\n")
    println("Please enter your orders (3 maximum).")    

    run breaking@{
        
        orders.forEachIndexed { i, o ->

            do {

                var confirm = false

                // Ask if user wants to skip
                while (i>0) {
                    print("Do you want to make another order? (Y/N): ")
                    when (readlnOrNull()?.lowercase()) {
                        "n" -> {
                            return@breaking
                        }
                        "y" -> {
                            break
                        }
                        else -> println("\tInvalid input. Please enter Y or N.")
                    }
                }

                println("\nOrder ${i + 1} Entry\n")

                print("Main [1-4]: ")
                o.main = readlnOrNull()?.toIntOrNull()?.takeIf { it in 1..4 } ?: 0
                println("\tSelected: ${mains[o.main]?.first}")

                print("Side [1-4]: ")
                o.side = readlnOrNull()?.toIntOrNull()?.takeIf { it in 1..4 } ?: 0
                println("\tSelected: ${sides[o.side]?.first}")

                print("Drink [1-4]: ")
                o.drink = readlnOrNull()?.toIntOrNull()?.takeIf { it in 1..4 } ?: 0
                println("\tSelected: ${drinks[o.drink]?.first}\n\n")

                // Confirm order
                while (true) {
                    print("Is this set meal correct? (Y/N): ")
                    when (readlnOrNull()?.lowercase()) {
                        "y" -> { confirm = true; break }
                        "n" -> { confirm = false; break }
                        else -> println("\tInvalid input. Please enter Y or N.")
                    }
                }

            } while (!confirm)
            
            println()
        }
    }

    // Cancel step
    while (true) {
        print("\nCancel any orders? (Input 1/2/3 or N): ")
        when (readlnOrNull()?.lowercase()) {
            "1" -> { orders[0] = Meal(0, 0, 0); println("\tOrder 1 cancelled.\n") }
            "2" -> { orders[1] = Meal(0, 0, 0); println("\tOrder 2 cancelled.\n") }
            "3" -> { orders[2] = Meal(0, 0, 0); println("\tOrder 3 cancelled.\n") }
            "n" -> break
            else -> println("\tInvalid input.\n")
        }
    }

    // Print final orders and total
    var count = 0
    var total = 0.0f
    println("\nFinal Orders")
    println("=============================")

    orders.forEach { o ->

       if (o.price != 0.0f) {
           println("Order ${++count}:")
            val price = if (o.main == setMealOfTheDay.main &&
                            o.side == setMealOfTheDay.side &&
                            o.drink == setMealOfTheDay.drink
            ) {
                println(" Set Meal of the Day (-15%)")
                discountedPrice
            } else {
                o.price
            }

            if (o.main != 0) println("\tMain: ${mains[o.main]?.first} \t\t PHP ${mains[o.main]?.second}")
            if (o.side != 0) println("\tSide: ${sides[o.side]?.first} \t\t PHP ${sides[o.side]?.second}")
            if (o.drink != 0) println("\tDrink: ${drinks[o.drink]?.first} PHP \t\t ${drinks[o.drink]?.second}")

            println("\tSubtotal:\t\t PHP ${"%.2f".format(price)}\n")
            total += price
        }
    }

    println("=============================")

    println("Total Amount Due: PHP ${"%.2f".format(total)}")
}