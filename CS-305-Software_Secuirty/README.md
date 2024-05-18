# Artemis Financial Software Security Enhancements

## Client Overview
**Client:** Artemis Financial  
**Software Requirements:** Artemis Financial needed to modernize its operations with the most current and effective software security measures. The company required a file verification step in its web application to ensure secure communications and wanted to add a checksum verification step for data integrity during transfers.

## Security Vulnerabilities and Solutions
**Issue Addressed:** The company wanted to ensure secure communications and data integrity in its web application. The primary security vulnerabilities identified were the lack of data integrity checks and insecure data transmission.

**What was Done Well:**
- **Identification and Suppression of False Positives:** Utilized the OWASP Dependency-Check tool to identify and suppress known false positives, ensuring a clean and actionable report. (this made alot of sense in hindsight)
- **Implementation of Secure Measures:** Added checksum verification to ensure data integrity and configured HTTPS to secure data transmission. (Although I am not sure I need the HTTPS correctly on this assignment)
- **Thorough Testing:** Conducted static and dynamic testing to verify no new vulnerabilities were introduced.

**Importance of Secure Coding:**
- **Data Protection:** Secure coding practices protect sensitive data from breaches and unauthorized access.
- **Compliance and Trust:** Ensuring software security helps meet regulatory requirements and builds client trust.
- **Risk Management:** Proactively managing security risks prevents potential incidents and maintains the company's reputation.

## Challenges and Insights
**Challenging Aspect:** The most challenging part was configuring and verifying the HTTPS setup, particularly handling self-signed certificates and ensuring the web application responded securely.

**Helpful Aspect:** Using the OWASP Dependency-Check tool was helpful in identifying dependencies with known vulnerabilities and ensuring the software components were up-to-date and secure.

## Increasing Layers of Security
**Security Layers Added:**
- **Checksum Verification:** Added to ensure data integrity during transfers.
- **HTTPS Configuration:** Implemented to secure data transmission.

**Future Assessments:**
- **Vulnerability Scanners:** Use tools like OWASP Dependency-Check, Snyk, or SonarQube for continuous vulnerability assessments.
- **Mitigation Techniques:** Apply industry best practices, regular updates, and comprehensive testing to mitigate identified vulnerabilities.

## Ensuring Functionality and Security
**Verification Process:**
- **Functional Testing:** Ran the application to ensure it started and functioned correctly without errors.
- **Static Testing:** Used OWASP Dependency-Check to verify no new vulnerabilities were introduced after refactoring.
- **Manual Code Review:** Conducted a manual review of the code to identify and resolve any potential syntactical, logical, or security issues.

## Resources and Tools
**Helpful Resources and Tools:**
- **OWASP Dependency-Check:** For identifying and managing vulnerabilities in dependencies.
- **Java Keytool:** For generating and managing SSL certificates.
- **Spring Boot Framework:** For building and configuring secure web applications.
- **Manual Code Reviews:** To ensure code quality and identify potential security issues.

## Demonstrating Skills to Future Employers
**Showcasing Skills:**
- **Comprehensive Security Enhancements:** Demonstrated ability to identify, address, and mitigate security vulnerabilities in a real-world scenario.
- **Use of Industry Tools:** Proficiency in using tools like OWASP Dependency-Check for security assessments.
- **Secure Coding Practices:** Application of secure coding practices to enhance data integrity and secure communications.
- **Detailed Documentation:** Ability to document processes, enhancements, and testing results effectively.

This assignment showcases a robust approach to enhancing software security, demonstrating skills that are highly valuable to potential employers in the field of software development and cybersecurity.
