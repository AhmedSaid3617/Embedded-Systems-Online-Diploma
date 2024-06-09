MEMORY
{
    flash(RX) : o = 0x00000000, l = 256K
    sram(RWX) : o = 0x40000000, l = 32K
}

SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = .;
    } > flash

    .data : {
        _S_DATA = .;
        *(.data)
        _E_DATA = .;
    }> sram AT> flash

    .bss : {
        _S_bss = .;
        *(.bss*)
        _E_bss = .;

        . = ALIGN(4);
        . = . + 1024;
        _stack_top = .;
    } > sram
}