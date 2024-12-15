import { useEffect, useState } from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { readFile } from 'react-native-turbofs';

export default function App() {
  const [content, setContent] = useState('');

  useEffect(() => {
    const read = async () => {
      const cont = await readFile('path/of/the/file');
      setContent(cont);
      console.log('🚀 ~ read ~ cont:', cont);
    };
    read();
  }, []);
  return (
    <View style={styles.container}>
      <Text style={styles.text}>Result: {content}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#000',
  },
  text: {
    color: '#FFF',
  },
});
