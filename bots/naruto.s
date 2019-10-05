.name       "Naruto"
.comment    "Raseeeeeeeengan"

zaloop:
        sti r1, %7, %1
vadaphone:
        live %0
        ld %0, r2
        fork %:zaloop
        zjmp %:vadaphone
