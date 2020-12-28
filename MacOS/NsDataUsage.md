```

- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error
{
    if (error)
    {
        NSLog(@"Error updating value for characteristic %@ error: %@", characteristic.UUID, [error localizedDescription]);
        return;
    }
    if([characteristic.UUID isEqual:[CBUUID UUIDWithString:@"FFF4"]] && characteristic.value){
        //맥 받기 프로세스
        NSData * updateValue = characteristic.value;
        NSLog(@"updateValue: %p", &updateValue);

        //딕셔너리로 저장하는 방법 //전체20바이트를 String형태로 보기가능
        NSMutableDictionary* userInfo = [NSMutableDictionary dictionary];
        [userInfo setObject:updateValue forKey:@"mac"];
        NSLog(@"userInfo: %@", userInfo);
        
        //한바이트씩 불러오는 방법 //단, 맨앞하나만 가져올수 있음.
        NSData *data = [userInfo objectForKey:@"battery"];
        int8_t value = 0;
        [data getBytes:&value length:sizeof (value)];
        
        //한칸씩 이동하면서 불러오는 방법 //4바이트씩 가져와서 읽을때, 4칸씩 넘겨읽거나, 1칸씩 읽고 나머지3개버려야함.
        NSMutableString *str_mac = [NSMutableString string];
        uint8_t* dataPointer = (uint8_t*)[updateValue bytes];
        for (int i=1; i<=6; i++)
        {
            dataPointer += 1;
            uint32_t BigEndianData = (uint32_t)CFSwapInt32BigToHost(*(uint32_t*)dataPointer);
            NSLog(@"BigEndianData : %x", BigEndianData/0x100000);

            NSString *mac_sub = [@(BigEndianData/0x100000) stringValue];
            NSLog(@"mac_sub : %@", mac_sub);
            
            //NSString *sub = [[@(BigEndianData/100000) stringValue] substringToIndex:2];
            //NSLog(@"sub : %@", sub);
            [str_mac appendString: mac_sub];
            if (i != 6) { [str_mac appendString: @":"];
            }
        }
        NSLog(@"str_mac: %@", str_mac);
        
        //한바이트씩 쉬프트연산으로 불러오는 방법 + hex를 dec형태로 변환하여 NSstring형태로 바꿈.
        NSString* result = NSDataToHex(updateValue);
        NSLog(@"result : %@", result);
        
    }
}

```


```

static inline char itoh(int i) {
    if (i > 9) return 'A' + (i - 10);
    return '0' + i;
}

NSString * NSDataToHex(NSData *data) {
    NSUInteger i, len;
    unsigned char *buf, *bytes;

    len = 6;
    bytes = (unsigned char*)data.bytes;
    buf = malloc(len*3);

    for (i=0; i<len; i++) {
        buf[i*3] = itoh((bytes[i] >> 4) & 0xF);
        buf[i*3+1] = itoh(bytes[i] & 0xF);
        if (i !=5) { buf[i*3+2] = ':'; }
    }
    return [[NSString alloc] initWithBytesNoCopy:buf
                                          length:len*3
                                        encoding:NSASCIIStringEncoding
                                    freeWhenDone:YES];
}

```
