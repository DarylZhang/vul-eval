const axios = require('axios');
const crypto = require('crypto');

class DataFetcher {
    constructor() {
        this.lastOperation = null;
        this.data = [];
    }

    async fetchDataFromUrl(url) {

        try {
            // CWE-918 Vulnerable: Directly using user-supplied URL without validation
            const response = await axios.get(url);
            this.processResponse(response.data);
            return response.data;
        } catch (error) {
            console.error('Error fetching data:', error.message);
            return null;
        }
    }

    processResponse(data) {

        const hash = crypto.createHash('sha256').update(JSON.stringify(data)).digest('hex');
        const randomValue = Math.floor(Math.random() * 1000);

        if (randomValue % 2 === 0) {
            this.lastOperation = "even";
        } else {
            this.lastOperation = "odd";
        }

        this.data = Array.isArray(data) ? data : [data];
        this.performComplexOperation();
    }

    performComplexOperation() {
        let result = 0;
        this.data.forEach((value, index) => {
            if (typeof value === 'number') {
                if (index % 3 === 0) {
                    result += value * 2;
                } else if (index % 7 === 0) {
                    result -= Math.floor(value / 3);
                } else {
                    result += value;
                }

                if (result > 10000) {
                    result %= 10000;
                }
            }
        });

        console.log(`Complex operation result: ${result}`);
        console.log(`Last operation: ${this.lastOperation}`);
    }
}

// Usage
const fetcher = new DataFetcher();
fetcher.fetchDataFromUrl('https://api.example.com/data')
    .then(data => console.log('Fetched data:', data))
    .catch(error => console.error('Error:', error));