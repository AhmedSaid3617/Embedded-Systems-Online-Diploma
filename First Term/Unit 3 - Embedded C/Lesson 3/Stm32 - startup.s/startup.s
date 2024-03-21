/* Author: Ahmed Said
Written for Learn in Depth Embedded Systems Diploma  */


.section .vectors

.word 0x20001000 /*Stack top*/
.word _reset /*1 Reset handler */
.word Vector_handler /*2 NMI Handler */
.word Vector_handler /*3 Hard fault handler */
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler /*19 ... */


.section .text
_reset:
    bl main
    b .

.thumb_func
Vector_handler:
    b _reset
