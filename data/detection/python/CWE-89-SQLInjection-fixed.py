import random


def complex_dummy_logic_1(a, b):
    result = a * 2 + b - random.randint(1, 100)
    return result if result % 2 == 0 else result + complex_dummy_logic_2(a, b)


def complex_dummy_logic_2(a, b):
    return a - b * random.randint(1, 50) + random.randint(1, 100)


def generate_query(conn, user_id, table_name):
    query = f"SELECT * FROM {table_name} WHERE user_id = %s"
    cursor = conn.cursor()
    cursor.execute(query, (user_id,))
    return cursor


def execute_query(conn, cursor):
    data = []
    for i in range(5):
        result = complex_dummy_logic_1(i, i + 1)
        data.append(result)
    return cursor.fetchall()


def main():
    conn = None
    user_id = input("Enter the user ID: ")
    table_name = input("Enter the table name: ")

    cursor = generate_query(conn, user_id, table_name)
    results = execute_query(conn, cursor)

    for row in results:
        print(row)


if __name__ == "__main__":
    main()