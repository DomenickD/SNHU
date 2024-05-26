import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class ContactServiceTest {
    private ContactService service;

    @Before
    public void setUp() {
        service = new ContactService();
    }

    @Test
    public void testAddContact() {
        Contact contact = new Contact("1", "Alice", "Smith", "1234567890", "123 Main St");
        service.addContact(contact);
        assertNotNull(service);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testAddDuplicateContact() {
        Contact contact = new Contact("1", "Alice", "Smith", "1234567890", "123 Main St");
        service.addContact(contact);
        service.addContact(contact);  // This should throw an exception
    }

    @Test
    public void testDeleteContact() {
        Contact contact = new Contact("1", "Alice", "Smith", "1234567890", "123 Main St");
        service.addContact(contact);
        service.deleteContact("1");
        assertNull(service);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testDeleteNonExistentContact() {
        service.deleteContact("99");  // This should throw an exception
    }

    @Test
    public void testUpdateContact() {
        Contact contact = new Contact("1", "Alice", "Smith", "1234567890", "123 Main St");
        service.addContact(contact);
        service.updateContact("1", "Bob", "Jones", "0987654321", "321 South St");
        Contact updated = service.getContact("1");
        assertEquals("Bob", updated.getFirstName());
        assertEquals("Jones", updated.getLastName());
        assertEquals("0987654321", updated.getPhone());
        assertEquals("321 South St", updated.getAddress());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testUpdateNonExistentContact() {
        service.updateContact("99", "Bob", "Jones", "0987654321", "321 South St");  // This should throw an exception
    }
}
