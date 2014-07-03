namespace cpp thrift.litescreen

//Defined all the constants....TO be used in fromDevice field of DeviceData
// More constants can be added in the future like MacOSX,ios,android etc

const i32 FROM_LINUX=0;
const i32 FROM_WINDOWS = 1;

/**
 * A structure that will be passed when the app first connects
 * So that both client and server can know before hand what kind
 * of data are expected
 */
struct DeviceData {
    1:i32 width,
    2:i32 height,
    3:i32 depth,
    4:i32 bits_per_pixel,
    5:i32 bytes_per_line,
    6:i32 byteorder,
    7:i32 fromDevice
}

/**
 * A structure that will be passed when actual data will be transferred
 */
struct ImageData {
    1:binary data,
    2:i32 orig_size
    3:i32 compressed_size
}

service litescreen {
    // Function that actually initializes the handshake
    void initializeHandshake(1:DeviceData data),
    // Function that actually sends data
    void sendImage(1:ImageData data)
}
