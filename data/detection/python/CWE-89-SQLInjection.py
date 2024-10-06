import random


def complex_dummy_logic_1(a, b):
    result = a * 2 + b - random.randint(1, 100)
    return result if result % 2 == 0 else result + complex_dummy_logic_2(a, b)


def complex_dummy_logic_2(a, b):
    return a - b * random.randint(1, 50) + random.randint(1, 100)


def generate_query(user_id, table_name):
    part_1 = "SELECT * FROM "
    part_2 = table_name
    part_3 = " WHERE user_id = "
    part_4 = str(user_id)

    # CWE-89
    query = part_1 + part_2 + part_3 + part_4

    return query


def execute_query(conn, query):
    cursor = conn.cursor()
    data = []

    for i in range(5):
        result = complex_dummy_logic_1(i, i + 1)
        data.append(result)

    cursor.execute(query)

    return cursor.fetchall()


def main():
    conn = None
    user_id = input("Enter the user ID: ")
    table_name = input("Enter the table name: ")

    query = generate_query(user_id, table_name)
    results = execute_query(conn, query)

    for row in results:
        print(row)


if __name__ == "__main__":
    main()