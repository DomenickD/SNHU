package com.snhu.sslserver;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HashController {

    @GetMapping("/hash")
    public String getHash() {
        // Example data to generate hash
        String testData = "Hello World Check Sum!";
        try {
            String checksum = ChecksumUtil.generateChecksum(testData);
            return "Checksum: " + checksum;
        } catch (Exception e) {
            e.printStackTrace();
            return "Error generating checksum";
        }
    }
}
