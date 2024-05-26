import static org.junit.Assert.*;
import org.junit.Test;

public class ContactTest {

    @Test(expected = IllegalArgumentException.class)
    public void testContactIdTooLong() {
        new Contact("12345678901", "Alice", "Smith", "1234567890", "123 Main St");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testContactIdNull() {
        new Contact(null, "Alice", "Smith", "1234567890", "123 Main St");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testFirstNameTooLong() {
        new Contact("1", "AliceBobs", "Smith", "1234567890", "123 Main St");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testLastNameTooLong() {
        new Contact("1", "Alice", "Smithsonian", "1234567890", "123 Main St");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPhoneNotExactDigits() {
        new Contact("1", "Alice", "Smith", "123456789", "123 Main St");
    }

    @Test(expected = IllegalArgumentException.class)
    public void testAddressTooLong() {
        new Contact("1", "Alice", "Smith", "1234567890", "123 Main St, Suite 101, Apartment 10");
    }

    @Test
    public void testValidContact() {
        Contact contact = new Contact("1", "Alice", "Smith", "1234567890", "123 Main St");
        assertNotNull(contact);
        assertEquals("Alice", contact.getFirstName());
        assertEquals("Smith", contact.getLastName());
        assertEquals("1234567890", contact.getPhone());
        assertEquals("123 Main St", contact.getAddress());
    }
}
