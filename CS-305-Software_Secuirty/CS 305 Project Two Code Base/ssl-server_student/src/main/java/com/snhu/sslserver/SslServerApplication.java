package com.snhu.sslserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
//import org.springframework.web.bind.annotation.RestController;


@SpringBootApplication
public class SslServerApplication {
	@GetMapping("/hash")
	public static void main(String[] args) {
		SpringApplication.run(SslServerApplication.class, args);
		
		try {
			String testData = "Hello World Check Sum!";
            String checksum = ChecksumUtil.generateChecksum(testData);
            System.out.println("Checksum: " + checksum);
        } catch (Exception e) {
            e.printStackTrace();
        }
	}

}
//FIXME: Add route to enable check sum return of static data example:  String data = "Hello World Check Sum!";