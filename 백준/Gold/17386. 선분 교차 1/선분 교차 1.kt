import java.io.*
import java.util.*

fun main() = BufferedReader(InputStreamReader(System.`in`)).run {
    var token = StringTokenizer(readLine())
    val x1 = token.nextToken().toLong()
    val y1 = token.nextToken().toLong()
    val x2 = token.nextToken().toLong()
    val y2 = token.nextToken().toLong()

    token = StringTokenizer(readLine())

    val x3 = token.nextToken().toLong()
    val y3 = token.nextToken().toLong()
    val x4 = token.nextToken().toLong()
    val y4 = token.nextToken().toLong()

    if ((ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0) &&
        (ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0)
    ) {
        println(1)
    } else {
        println(0)
    }
}

fun ccw(x1: Long, y1: Long, x2: Long, y2: Long, x3: Long, y3: Long): Int {
    val calc = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1

    return if (calc > 0) {
        1
    } else if (calc == 0L) {
        0
    } else {
        -1
    }
}