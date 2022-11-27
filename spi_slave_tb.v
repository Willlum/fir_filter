`timescale 1ns / 1ps

module spi_slave_tb;

reg CLK;
reg SCLK;
reg MOSI;
reg SSEL;

wire MISO;

initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,spi_slave_tb);
end


SPI_slave uut(  .clk(CLK),
                .SCK(SCLK), 
                .MOSI(MOSI),
                .MISO(MISO),
                .SSEL(SSEL)
                );

initial begin
    CLK = 0;
    SCLK = 0;
    MOSI = 1; 
    SSEL = 1;
    #500 SSEL = 0;
end

initial begin
    #1000000 $finish;
end

initial begin
    forever begin
        #63 CLK = !CLK;
    end
end

initial begin
    forever begin
        #500 SCLK = !SCLK;
    end
end

endmodule